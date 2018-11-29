delimiter $$
DROP PROCEDURE IF EXISTS SwapItem$$
CREATE PROCEDURE SwapItem()
BEGIN
    declare done int default 0;
    declare counter int default 0;
    declare prev_id int;
    declare prev_name varchar(100);
    declare now_id int;
    declare now_name varchar(100);
    declare cur cursor for select id, student from seat; 
    DECLARE  CONTINUE HANDLER FOR NOT FOUND  SET  done = 1;
    
    open cur;
    REPEAT

    set counter=counter+1;
    fetch cur into now_id, now_name;

    if not done then
    if counter % 2 != 0 then
        set prev_id = now_id;
        set prev_name = now_name;
    else 
        set @sqlcmd = concat('update seat set student="',prev_name,'" where id=', now_id);
        prepare sqlcmd_ from @sqlcmd;
        execute sqlcmd_;

        set @sqlcmd = concat('update seat set student="',now_name, '" where id=', prev_id);
        prepare sqlcmd_ from @sqlcmd;
        execute sqlcmd_;
    end if;    
    end if;

    UNTIL done END REPEAT;
    close cur;
END$$

CALL  SwapItem();$$

