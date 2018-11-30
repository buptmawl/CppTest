select if(id%2=1,id+1,id-1) as id,student from seat where id <= (select floor(max(id)/2)*2  as max_id from seat) 
union all 
select id,student from seat where id > (select floor(max(id)/2)*2  as max_id from seat) order by id



select case
    when mod(id,2) != 0 and id = (select max(id) as sid from seat)  then id
    when mod(id,2) != 0 then id+1
    else id-1 end as id, student
from seat
order by id
