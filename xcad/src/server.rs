use crate::db::DBManager;
use actix_web::{middleware, web, App, HttpServer, Responder};
use std::sync::Arc;

const FETCH_ERR_MSG: &str = "Failed to fetch BIM object from database";

pub struct ServerManager {
    server_addr: &'static str,
    endpoint: &'static str,
    log_level: &'static str,
}

impl ServerManager {
    pub fn new(server_addr: &'static str, endpoint: &'static str, log_level: &'static str) -> Self {
        Self {
            server_addr,
            endpoint,
            log_level,
        }
    }

    pub async fn run(self, db: DBManager) -> std::io::Result<()> {
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

async fn fetch_obj_from_db(db: web::Data<Arc<DBManager>>) -> impl Responder {
    web::Json(db.get_obj("1").await.expect(FETCH_ERR_MSG))
}
