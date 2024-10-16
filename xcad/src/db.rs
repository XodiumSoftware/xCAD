use crate::bim::{BIMObject, Dim, Geo, Loc, Attr};
use rusqlite::{params, Connection, Result};
use std::sync::{Arc, Mutex};

#[derive(Clone)]
pub struct DBManager {
    conn: Arc<Mutex<Connection>>,
}

impl DBManager {
    pub fn new(db_url: &str) -> Result<Self> {
        Ok(Self {
            conn: Arc::new(Mutex::new(Connection::open(db_url)?)),
        })
    }

    pub fn set_obj(&self, bim: &BIMObject) -> Result<usize> {
        let conn = self.conn.lock().unwrap();
        conn.execute(
            "INSERT INTO bim_objects (
                id, name, desc, manufacturer, model_number, material, 
                length, width, height, category, cost, lifecycle_info, 
                performance_data, geometry, x, y, z, color, texture
            ) VALUES (?1, ?2, ?3, ?4, ?5, ?6, ?7, ?8, ?9, ?10, ?11, ?12, ?13, ?14, ?15, ?16, ?17, ?18, ?19)
            ON CONFLICT(id) DO UPDATE SET 
                name = excluded.name, desc = excluded.desc, manufacturer = excluded.manufacturer, 
                model_number = excluded.model_number, material = excluded.material, 
                length = excluded.length, width = excluded.width, height = excluded.height, 
                category = excluded.category, cost = excluded.cost, 
                lifecycle_info = excluded.lifecycle_info, performance_data = excluded.performance_data, 
                geometry = excluded.geometry, x = excluded.x, y = excluded.y, z = excluded.z, 
                color = excluded.color, texture = excluded.texture",
            params![
                bim.id, bim.name, bim.desc, bim.manufacturer, bim.model_number, bim.material, 
                bim.dimensions.as_ref().map(|d| d.length), bim.dimensions.as_ref().map(|d| d.width), bim.dimensions.as_ref().map(|d| d.height), 
                bim.category, bim.cost, bim.lifecycle_info, bim.performance_data, bim.geometry.as_ref().map(|g| g.data.clone()), 
                bim.location.as_ref().map(|l| l.x), bim.location.as_ref().map(|l| l.y), bim.location.as_ref().map(|l| l.z), 
                bim.attributes.as_ref().and_then(|a| a.color.clone()), bim.attributes.as_ref().and_then(|a| a.texture.clone())
            ],
        )
    }

    pub fn get_obj(&self, id: u32) -> Result<BIMObject> {
        let conn = self.conn.lock().unwrap();
        conn.query_row(
            "SELECT 
                id, name, desc, manufacturer, model_number, material, 
                length, width, height, category, cost, lifecycle_info, 
                performance_data, geometry, x, y, z, color, texture
            FROM bim_objects WHERE id = ?1",
            params![id],
            |row| {
                Ok(BIMObject {
                    id: row.get(0)?,
                    name: row.get(1)?,
                    desc: row.get(2)?,
                    manufacturer: row.get(3)?,
                    model_number: row.get(4)?,
                    material: row.get(5)?,
                    dimensions: Some(Dim {
                        length: row.get(6)?,
                        width: row.get(7)?,
                        height: row.get(8)?,
                    }),
                    category: row.get(9)?,
                    cost: row.get(10)?,
                    lifecycle_info: row.get(11)?,
                    performance_data: row.get(12)?,
                    geometry: Some(Geo {
                        data: row.get(13)?,
                    }),
                    location: Some(Loc {
                        x: row.get(14)?,
                        y: row.get(15)?,
                        z: row.get(16)?,
                    }),
                    attributes: Some(Attr {
                        color: row.get(17)?,
                        texture: row.get(18)?,
                    }),
                })
            },
        )
    }
}
