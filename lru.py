ref_str = input("Enter the reference string: ").split()
total_frames = int(input("Enter the number of frames: "))
frame = []
page_faults = 0
for page in ref_str:
    if page in frame:
        frame.remove(page)
        frame.append(page)
    else:
        page_faults += 1
        if len(frame) < total_frames:
            frame.append(page)
        else:
            frame.pop(0)
            frame.append(page)
    for f in frame:
        print(f, end=" ")
    print()
print(f"Page faults: {page_faults}")
