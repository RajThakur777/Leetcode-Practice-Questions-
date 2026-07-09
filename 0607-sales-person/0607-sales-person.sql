# Write your MySQL query statement below
SELECT s.name 
FROM SalesPerson as s
WHERE s.sales_id NOT IN (
    SELECT o.sales_id
    FROM Company as c
    INNER JOIN Orders as o
    ON c.com_id = o.com_id
    WHERE c.name = "RED"
);