# Write your MySQL query statement below
DELETE p1
FROM Person as p1
JOIN Person as p2
ON p1.email = p2.email
WHERE p1.id > p2.id;