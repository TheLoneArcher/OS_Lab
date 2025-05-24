ref_str = input("Enter the reference string: ").split()
total_frames = int(input("Enter the number of frames: "))
frame = []
freq = [] 
page_fault = 0
for i in range(len(ref_str)):
    page = ref_str[i]
    if page in frame:
        freq[frame.index(page)] += 1
    else:
        page_fault += 1
        if len(frame) < total_frames: 
            frame.append(page)
            freq.append(1)
        else:
            victim = freq.index(min(freq))
            frame[victim] = page
            freq[victim] = 1
    for f in frame:
        print(f, end = " ")
    print()
print(f"Page faults: {page_fault}")
