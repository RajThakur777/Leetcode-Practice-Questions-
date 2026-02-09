# Write your MySQL query statement below
SELECT e1.employee_id
FROM Employees as e1
LEFT JOIN 
Salaries as s1
ON e1.employee_id = s1.employee_id
WHERE s1.employee_id IS NULL

UNION

SELECT s1.employee_id
FROM Salaries as s1
LEFT JOIN 
Employees as e1
ON s1.employee_id = e1.employee_id
WHERE e1.employee_id IS NULL

ORDER BY employee_id ASC;