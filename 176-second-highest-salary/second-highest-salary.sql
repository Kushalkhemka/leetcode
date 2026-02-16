# Write your MySQL query statement below
SELECT(SELECT DISTINCT salary from Employee
WHERE salary<(SELECT MAX(salary) from Employee) 
ORDER BY salary DESC LIMIT 1) as SecondHighestSalary;