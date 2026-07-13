# Write your MySQL query statement below
SELECT m.employee_id , m.name , COUNT(*) as reports_count , ROUND(AVG(e.age)) as average_age
FROM Employees as m
JOIN Employees as e
ON m.employee_id = e.reports_to
GROUP BY m.employee_id
ORDER BY m.employee_id;