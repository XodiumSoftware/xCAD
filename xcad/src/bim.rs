use serde::{Deserialize, Serialize};

#[derive(Deserialize, Serialize, Clone)]
pub struct BIMObject {
    pub id: String,
    pub name: String,
    pub desc: String,
}

impl BIMObject {
    pub fn new(id: &str, name: &str, desc: &str) -> Self {
        Self {
            id: id.to_string(),
            name: name.to_string(),
            desc: desc.to_string(),
        }
    }
}
