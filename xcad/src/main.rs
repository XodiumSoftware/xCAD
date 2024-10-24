mod db;

use db::DBManager;
use rusqlite::Result;

fn main() -> Result<()> {
    let db = DBManager::new("xcad/data/xcad.db", "DEBUG")?;

    // Initialize the database schema
    db.init()?;

    // Set some data
    db.set_data("name", "John Doe")?;
    db.set_data("age", "30")?;

    // Get the data
    let name = db.get_data("name")?;
    let age = db.get_data("age")?;
    println!("Name: {:?}", name);
    println!("Age: {:?}", age);

    // Update the data
    db.update_data("age", "31")?;
    let updated_age = db.get_data("age")?;
    println!("Updated Age: {:?}", updated_age);

    // Delete the data
    db.delete_data("name")?;
    let deleted_name = db.get_data("name")?;
    println!("Deleted Name: {:?}", deleted_name);

    Ok(())
}
