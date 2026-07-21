# Write your MySQL query statement below
-- SELECT MAX(salary) as SecondHighestSalary
-- FROM Employee 
-- WHERE salary < (
--     SELECT MAX(salary) AS firstHighestSalary
--     FROM Employee
-- )
-- ORDER BY salary DESC
-- LIMIT 1;

WITH cte AS (
    SELECT salary,
    DENSE_RANK() OVER (ORDER BY salary DESC) AS rnk
    FROM Employee
)
SELECT MAX(Salary) AS SecondHighestSalary
FROM cte
WHERE rnk=2;
