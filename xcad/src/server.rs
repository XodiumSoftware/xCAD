use actix_web::{web, App, HttpResponse, HttpServer, Responder};
use actix_web_httpauth::middleware::HttpAuthentication;
use serde::{Deserialize, Serialize};
use std::sync::Arc;
use std::sync::Mutex;

use crate::auth::validator;
use crate::db::DBManager;

#[derive(Serialize, Deserialize)]
struct KeyValue {
    key: String,
    value: String,
}

#[derive(Serialize, Deserialize)]
struct Key {
    key: String,
}

pub struct Server {
    db: Arc<Mutex<DBManager>>,
    bind_address: String,
}

impl Server {
    pub fn new(db: DBManager, bind_address: &str) -> Self {
        Server {
            db: Arc::new(Mutex::new(db)),
            bind_address: bind_address.to_string(),
        }
    }

    pub async fn run(&self) -> std::io::Result<()> {
        let db = self.db.clone();
        HttpServer::new(move || {
            let auth = HttpAuthentication::bearer(validator);
            App::new()
                .app_data(web::Data::new(db.clone()))
                .wrap(auth)
                .route("/set_data", web::post().to(Server::set_data))
                .route("/get_data", web::post().to(Server::get_data))
                .route("/update_data", web::post().to(Server::update_data))
                .route("/delete_data", web::post().to(Server::delete_data))
                .route("/delete_table", web::post().to(Server::delete_table))
        })
        .bind(&self.bind_address)?
        .run()
        .await
    }

    async fn set_data(
        db: web::Data<Arc<Mutex<DBManager>>>,
        item: web::Json<KeyValue>,
    ) -> impl Responder {
        let db = db.lock().unwrap();
        match db.set_data(&item.key, &item.value) {
            Ok(_) => HttpResponse::Ok().body("Data set successfully"),
            Err(_) => HttpResponse::InternalServerError().body("Failed to set data"),
        }
    }

    async fn get_data(
        db: web::Data<Arc<Mutex<DBManager>>>,
        item: web::Json<Key>,
    ) -> impl Responder {
        let db = db.lock().unwrap();
        match db.get_data(&item.key) {
            Ok(Some(value)) => HttpResponse::Ok().json(KeyValue {
                key: item.key.clone(),
                value,
            }),
            Ok(None) => HttpResponse::NotFound().body("Data not found"),
            Err(_) => HttpResponse::InternalServerError().body("Failed to get data"),
        }
    }

    async fn update_data(
        db: web::Data<Arc<Mutex<DBManager>>>,
        item: web::Json<KeyValue>,
    ) -> impl Responder {
        let db = db.lock().unwrap();
        match db.update_data(&item.key, &item.value) {
            Ok(_) => HttpResponse::Ok().body("Data updated successfully"),
            Err(_) => HttpResponse::InternalServerError().body("Failed to update data"),
        }
    }

    async fn delete_data(
        db: web::Data<Arc<Mutex<DBManager>>>,
        item: web::Json<Key>,
    ) -> impl Responder {
        let db = db.lock().unwrap();
        match db.delete_data(&item.key) {
            Ok(_) => HttpResponse::Ok().body("Data deleted successfully"),
            Err(_) => HttpResponse::InternalServerError().body("Failed to delete data"),
        }
    }

    async fn delete_table(db: web::Data<Arc<Mutex<DBManager>>>) -> impl Responder {
        let db = db.lock().unwrap();
        match db.delete_table() {
            Ok(_) => HttpResponse::Ok().body("Table deleted successfully"),
            Err(_) => HttpResponse::InternalServerError().body("Failed to delete table"),
        }
    }
}
