    cout << endl;
    i = 0;
    int array[argc];
    while (i < argc)
    {
        array[i] = atoi(argv[i]);
    }

    for (int i = 0; i < argc; i++)
    {
        cout << array[i] << " ";
    }