/* Write your PL/SQL query statement below */
select d.name as department, e.name as employee, e.salary 
from employee e 
join department d
on e.departmentid = d.id
where 3 > (select count(distinct salary) from employee e1
            where e1.salary > e.salary and e1.departmentid = e.departmentid);