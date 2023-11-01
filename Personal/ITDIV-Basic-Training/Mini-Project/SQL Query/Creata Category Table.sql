USE WareHouseDb;

CREATE TABLE Categories (
	UserId uniqueidentifier NOT NULL,
	CategoryId INT NOT NULL IDENTITY(1, 1),
	CategoryName VARCHAR(255),

	FOREIGN KEY (UserId) REFERENCES Users,
	PRIMARY KEY(CategoryID)
)