USE WareHouseDb;

CREATE TABLE Users (
	UserId uniqueidentifier NOT NULL, 
	Email VARCHAR(255) NOT NULL,
	Password VARCHAR(255) NOT NULL,
	Name VARCHAR(255) NOT NULL,

	PRIMARY KEY (UserId)
);
