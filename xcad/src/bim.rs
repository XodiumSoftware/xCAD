use serde::{Deserialize, Serialize};

#[derive(Deserialize, Serialize, Clone, Default)]
pub struct BIMObject {
    pub id: u32,
    pub name: Option<String>,
    pub desc: Option<String>,
}

impl BIMObject {
    pub fn new(id: u32, name: Option<&str>, desc: Option<&str>) -> Self {
        Self {
            id,
            name: name.map(String::from),
            desc: desc.map(String::from),
        }
    }
}
