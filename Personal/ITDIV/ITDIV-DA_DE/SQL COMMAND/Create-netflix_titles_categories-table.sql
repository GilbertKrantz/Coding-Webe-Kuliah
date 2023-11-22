CREATE TABLE [netflix_titles_categories] (
    [categories] nvarchar(255),
    [show_id] float,
	FOREIGN KEY (show_id) REFERENCES netflix_titles(show_id)
)