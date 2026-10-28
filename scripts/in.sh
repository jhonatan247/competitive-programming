vim --cmd 'set autoread' \
    --cmd 'set updatetime=1000' \
    --cmd 'call timer_start(1000, {-> execute("checktime")}, {"repeat": -1})' \
    ~/in
