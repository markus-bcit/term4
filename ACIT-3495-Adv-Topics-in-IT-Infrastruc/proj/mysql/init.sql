use db;

CREATE TABLE users(
    id INT AUTO_INCREMENT PRIMARY KEY,
    name VARCHAR(255) NOT NULL,
    password VARCHAR(255) NOT NULL
);
INSERT INTO users (name, password)
VALUES ('user', 'password');

use db;
CREATE TABLE data_entries (
    id INT AUTO_INCREMENT PRIMARY KEY,
    data1 VARCHAR(255) NOT NULL,
    data2 VARCHAR(255) NOT NULL,
    data3 VARCHAR(255) NOT NULL
);
