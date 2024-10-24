use actix_web::dev::ServiceRequest;
use actix_web::Error;
use actix_web_httpauth::extractors::bearer::{BearerAuth, Config};
use actix_web_httpauth::extractors::AuthenticationError;
use jsonwebtoken::{decode, DecodingKey, Validation};
use serde::{Deserialize, Serialize};
use std::future::{ready, Ready};

#[derive(Debug, Serialize, Deserialize)]
struct Claims {
    sub: String,
    exp: usize,
}

pub fn validator(
    req: ServiceRequest,
    credentials: BearerAuth,
) -> Ready<Result<ServiceRequest, (Error, ServiceRequest)>> {
    let token = credentials.token();
    let decoding_key = DecodingKey::from_secret("DEBUG".as_ref());
    let config = Config::default();

    match decode::<Claims>(token, &decoding_key, &Validation::default()) {
        Ok(_) => ready(Ok(req)),
        Err(_) => ready(Err((AuthenticationError::from(config).into(), req))),
    }
}
