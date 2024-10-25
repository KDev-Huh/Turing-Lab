import { Sequelize } from "sequelize";
import dotenv from 'dotenv';

// Load environment variables from .env
dotenv.config();

const sequelize = new
Sequelize(process.env.DB_DATABASE2,
    process.env.DB_USER, process.env.DB_PASSWORD, {
        host:process.env.DB_HOST,
        dialect:'mysql',
        logging:(...msg) => console.log(msg)
    }
)

try {
    await sequelize.authenticate();
    console.log('Connection has been established successfully.');
} catch(error) {
    console.error('Unable to connect to the database:', error);
} finally {
    sequelize.close();
}