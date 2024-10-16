use crate::bim::BIMObject;
use crate::db::DBManager;
use actix_web::error::ErrorInternalServerError;
use actix_web::{middleware, web, App, HttpServer, Responder, Result};
use std::io::Result as IoResult;

pub struct ServerManager {
    server_addr: &'static str,
    endpoint: &'static str,
}

impl ServerManager {
    pub fn new(server_addr: &'static str, endpoint: &'static str) -> Self {
        Self {
            server_addr,
            endpoint,
        }
    }

    pub async fn run(self, db: DBManager) -> IoResult<()> {
        HttpServer::new(move || {
            App::new()
                .app_data(web::Data::new(db.clone()))
                .wrap(middleware::Logger::default())
                .route(self.endpoint, web::get().to(Self::fetch_data))
        })
        .bind(self.server_addr)?
        .run()
        .await
    }

    async fn fetch_data(db: web::Data<DBManager>, id: web::Path<String>) -> Result<impl Responder> {
        match web::block(move || db.get_obj(&id))
            .await
            .map_err(ErrorInternalServerError)?
        {
            Ok(obj) => Ok(web::Json(obj)),
            Err(_) => Ok(web::Json(BIMObject::default())),
        }
    }
}
