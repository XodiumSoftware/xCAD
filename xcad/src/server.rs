use crate::bim::BIMObject;
use crate::db::DBManager;
use actix_web::error::ErrorInternalServerError;
use actix_web::{middleware, web, App, HttpServer, Responder, Result};
use std::io::Result as IoResult;
use std::sync::Arc;

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
        let db = Arc::new(db);

        HttpServer::new(move || {
            App::new()
                .app_data(web::Data::new(Arc::clone(&db)))
                .wrap(middleware::Logger::default())
                .route(self.endpoint, web::get().to(fetch_obj_from_db))
        })
        .bind(self.server_addr)?
        .run()
        .await
    }
}

async fn fetch_obj_from_db(db: web::Data<Arc<DBManager>>) -> Result<impl Responder> {
    let result = web::block(move || db.get_obj("1"))
        .await
        .map_err(|e| ErrorInternalServerError(e))?;

    match result {
        Ok(bim_object) => Ok(web::Json(bim_object)),
        Err(_) => Ok(web::Json(BIMObject::default())),
    }
}
