use actix_web::{middleware, web, App, HttpServer, Responder};
use env_logger::Env;
use serde::{Deserialize, Serialize};

#[derive(Deserialize, Serialize, Clone)]
struct BIMObject {
    id: String,
    name: String,
    description: String,
}

async fn get_bim_object(data: web::Data<AppState>) -> impl Responder {
    web::Json(data.bim_object.clone())
}

#[derive(Clone)]
struct AppState {
    bim_object: BIMObject,
}

#[actix_web::main]
async fn main() -> std::io::Result<()> {
    env_logger::init_from_env(Env::default().default_filter_or("info"));

    let app_state = web::Data::new(AppState {
        bim_object: BIMObject {
            id: "1".to_string(),
            name: "Sample Object".to_string(),
            description: "A sample BIM object".to_string(),
        },
    });

    HttpServer::new(move || {
        App::new()
            .app_data(app_state.clone())
            .wrap(middleware::Logger::default())
            .route("/bim", web::get().to(get_bim_object))
    })
    .bind("127.0.0.1:8080")?
    .run()
    .await
}
