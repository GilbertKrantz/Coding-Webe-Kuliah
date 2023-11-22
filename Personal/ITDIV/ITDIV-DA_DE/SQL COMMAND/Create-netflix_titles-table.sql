CREATE TABLE [netflix_titles] (
    [duration_minutes] float,
    [duration_seasons] float,
    [type] nvarchar(255),
    [title] nvarchar(255),
    [date_added] datetime,
    [release_year] float,
    [rating] nvarchar(255),
    [description] nvarchar(255),
    [show_id] float PRIMARY KEY
)