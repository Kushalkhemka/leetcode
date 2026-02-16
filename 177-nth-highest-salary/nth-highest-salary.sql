CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  DECLARE off INT;              -- ADDED: local variable
  SET off = N - 1;   
  RETURN (
      # Write your MySQL query statement below.
        Select DISTINCT salary as getNthHighestSalary from employee
        order by salary desc
        limit 1 offset off
  );
END