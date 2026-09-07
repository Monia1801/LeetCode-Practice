SELECT Department,Employee,Salary
FROM(
    SELECT d.name as Department,e.name as Employee,e.salary AS Salary,
    RANK() OVER(
    PARTITION BY d.name
    ORDER BY e.salary DESC
    ) as rnk
    FROM Employee e
    LEFT JOIN DEPARTMENT d
    ON e.departmentId=d.id
) t
WHERE rnk=1;
