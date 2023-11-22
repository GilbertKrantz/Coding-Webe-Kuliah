CREATE TABLE [netflix_titles_cast] (
    [cast] nvarchar(255),
    [show_id] float,
	FOREIGN KEY (show_id) REFERENCES netflix_titles(show_id)
)