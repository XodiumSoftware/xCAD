// use serde::{Deserialize, Serialize};

// #[derive(Deserialize, Serialize, Clone, Default)]
// pub struct BIMObject {
//     pub id: u32,
//     pub name: Option<String>,
//     pub desc: Option<String>,
//     pub manufacturer: Option<String>,
//     pub model_number: Option<String>,
//     pub material: Option<String>,
//     pub dimensions: Option<Dim>,
//     pub category: Option<String>,
//     pub cost: Option<f64>,
//     pub lifecycle_info: Option<String>,
//     pub performance_data: Option<String>,
//     pub geometry: Option<Geo>,
//     pub location: Option<Loc>,
//     pub attributes: Option<Attr>,
// }

// #[derive(Deserialize, Serialize, Clone, Default)]
// pub struct Dim {
//     pub length: f64,
//     pub width: f64,
//     pub height: f64,
// }

// #[derive(Deserialize, Serialize, Clone, Default)]
// pub struct Geo {
//     pub data: String,
// }

// #[derive(Deserialize, Serialize, Clone, Default)]
// pub struct Loc {
//     pub x: f64,
//     pub y: f64,
//     pub z: f64,
// }

// #[derive(Deserialize, Serialize, Clone, Default)]
// pub struct Attr {
//     pub color: Option<String>,
//     pub texture: Option<String>,
// }

// impl BIMObject {
//     pub fn new(
//         id: u32,
//         name: Option<&str>,
//         desc: Option<&str>,
//         manufacturer: Option<&str>,
//         model_number: Option<&str>,
//         material: Option<&str>,
//         dimensions: Option<Dim>,
//         category: Option<&str>,
//         cost: Option<f64>,
//         lifecycle_info: Option<&str>,
//         performance_data: Option<&str>,
//         geometry: Option<Geo>,
//         location: Option<Loc>,
//         attributes: Option<Attr>,
//     ) -> Self {
//         Self {
//             id,
//             name: name.map(String::from),
//             desc: desc.map(String::from),
//             manufacturer: manufacturer.map(String::from),
//             model_number: model_number.map(String::from),
//             material: material.map(String::from),
//             dimensions,
//             category: category.map(String::from),
//             cost,
//             lifecycle_info: lifecycle_info.map(String::from),
//             performance_data: performance_data.map(String::from),
//             geometry,
//             location,
//             attributes,
//         }
//     }
// }
