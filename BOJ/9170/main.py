while True:
    try:
        s = input()
        print(eval(s))
    except EOFError:
        break
