# Write your MySQL query statement below
select e.name as Employee from Employee e, Employee m
where e.managerId=m.id AND e.salary > m.salary;