select 
    a.machine_id , 
    round(avg(b.timestamp - a.timestamp) , 3) as processing_time
from Activity a
join Activity b
on a.machine_id = b.machine_id
where a.activity_type = 'start' and b.activity_type = 'end'
group by a.machine_id;