CREATE TABLE [netflix_titles_countries] (
    [country] nvarchar(255),
    [show_id] float,
	FOREIGN KEY (show_id) REFERENCES netflix_titles(show_id)
)