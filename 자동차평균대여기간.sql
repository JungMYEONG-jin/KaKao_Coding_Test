-- 코드를 입력하세요
select car_mean_info.CAR_ID, car_mean_info.AVERAGE_DURATION from (

SELECT CAR_ID, ROUND(sum(DATEDIFF(END_DATE, START_DATE)+1)/count(CAR_ID), 1) as AVERAGE_DURATION
from CAR_RENTAL_COMPANY_RENTAL_HISTORY
group by CAR_ID
) as car_mean_info
where car_mean_info.AVERAGE_DURATION >= 7.0
order by car_mean_info.AVERAGE_DURATION DESC, car_mean_info.CAR_ID DESC;
