def condense_meeting_times(slots):
    print("test")




def main():
    time_slots = [(0, 1), (3, 5), (4, 8), (10, 12), (9, 10)]
    condense_meeting_times(time_slots)


if __name__:
    import cProfile
    cProfile.run("main()")

