import { Sequelize, DataTypes } from "sequelize";

const sequelize = new Sequelize({   // 인스턴스
    dialect: 'sqlite',
    storage: './database.sqlite'    // Path to the SQLite database file
})

const User = sequelize.define('User', {
    // Define attributes
    username: {
        type: DataTypes.STRING,
        allowNull: false
    },
    email: {
        type: DataTypes.STRING,
        allowNull: false,
        unique: true
    }
})

// (async ()=> {
//     await User.sync();  // This will create the table 테이블이랑 클래스랑 일치시키기
// })();

const exec = async ()=> {
    await User.sync();  // This will create the table 테이블이랑 클래스랑 일치시키기
};

exec()

// sequelize.define also returns the model
console.log(User === sequelize.models.User); // true