ref_str = input("Enter the reference string: ").split()
total_frames = int(input("Enter the number of frames: "))
page_faults = 0
frame = []
victim = 0
print("FIFO Page Replacement")
for i in range(len(ref_str)):
    if ref_str[i] not in frame:
        page_faults += 1
        if len(frame) < total_frames:
            frame.append(ref_str[i])
        else:
            frame[victim] = ref_str[i]
            victim = (victim + 1) % 3
    for i in frame: print(i, end = " ")
    print()
print(f"\nNumber of page faults: {page_faults}")

