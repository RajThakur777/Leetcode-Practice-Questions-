# Write your MySQL query statement below
SELECT p1.firstName , p1.lastName , a.city , a.state
FROM Person as p1
LEFT JOIN 
Address as a
ON p1.personId = a.personId;