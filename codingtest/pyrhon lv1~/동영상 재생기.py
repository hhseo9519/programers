from datetime import datetime, timedelta

def solution(video_len, pos, op_start, op_end, commands):
    conv_time = lambda target : datetime.strptime(target, "%M:%S")
    video_len = conv_time(video_len)
    pos = conv_time(pos)
    op_start = conv_time(op_start)
    op_end = conv_time(op_end)

    if op_start <= pos and pos <= op_end:
        pos = op_end

    for command in commands:
        if command == 'prev':
            if pos - timedelta(seconds=10) > conv_time("0:0"):
                pos = pos - timedelta(seconds=10)
            else:
                pos = conv_time("0:0")
        elif command == 'next':
            if pos + timedelta(seconds=10) < video_len:
                pos = pos + timedelta(seconds=10)
            else:
                pos = video_len

        if op_start <= pos and pos <= op_end:
            pos = op_end
    return pos.strftime("%M:%S")
