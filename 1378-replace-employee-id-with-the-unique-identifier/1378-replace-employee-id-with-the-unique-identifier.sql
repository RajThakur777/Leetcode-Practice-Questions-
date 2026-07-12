# Write your MySQL query statement below
SELECT ep.unique_id , e.name
FROM Employees as e
LEFT JOIN EmployeeUNI as ep
ON e.id = ep.id