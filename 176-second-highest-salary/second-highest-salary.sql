# Write your MySQL query statement below
SELECT MAX(salary) as SecondHighestSalary
FROM Employee 
WHERE salary < (
    SELECT MAX(salary) AS firstHighestSalary
    FROM Employee
)
ORDER BY salary DESC
LIMIT 1;