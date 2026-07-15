# Write your MySQL query statement below
SELECT person_name
FROM (
    SELECT person_name , SUM(weight) OVER (ORDER BY turn) as wt
    FROM Queue
) t
WHERE wt <= 1000
ORDER BY wt DESC
LIMIT 1;