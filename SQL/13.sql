-- write a SQL query to list the names of all people who starred in a movie in which Kevin Bacon also starred

-- finds the people who starred in movies with kevin bacon
SELECT DISTINCT name
FROM stars JOIN people ON stars.person_id = people.id
WHERE movie_id IN

-- finds all movies kevin bacon has starred in
(SELECT movie_id
FROM people JOIN stars ON stars.person_id = people.id JOIN movies ON movies.id = stars.movie_id
WHERE name = "Kevin Bacon" AND birth = 1958)

-- remove kevin bacon from the list
AND name != 'Kevin Bacon';
