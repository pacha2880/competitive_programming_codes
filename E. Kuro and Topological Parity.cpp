// https://codeforces.com/contest/979/problem/E
/*
messi siemppre esta arriba
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⡞⠉⡟⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⣀⡠⠖⠒⠓⣦⢀⡞⠀⢰⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⣴⣪⠟⢙⣶⣴⣿⣿⣿⠟⠀⢲⡎⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⢻⣏⣠⣿⣿⣿⢿⣿⠋⠀⢀⡏⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢰⠋⢳⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⢹⣹⣿⣿⡷⢖⢿⠭⠄⡾⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣤⣄⢀⣀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⠀⢸⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⡞⠀⣏⡏⢀⣈⣄⢀⡾⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⣾⣶⣾⣿⣯⣷⣶⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣠⠌⠓⢆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⢧⠀⡉⣄⣠⣝⠙⡾⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡢⣄⠀⠀⠀⠀⠀⢀⣼⢁⣠⡾⠈⠳⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⢸⠻⣖⢨⣻⡿⢱⠇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⠞⠉⠀⠀⠀⠉⠙⠿⣿⣿⣿⣿⣞⣦⡀⠀⠀⢠⠞⣶⡾⣿⣅⣴⠇⢈⡱⡄⠀⠀⠀⠀⠀⠀⠀
⠀⢸⣶⠸⣆⣯⣥⣼⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣴⣿⣥⠀⢀⣀⡀⠀⠀⠀⠀⡨⢻⣿⣿⣿⣿⣷⡀⠀⢻⣴⣿⣴⣿⣿⣿⣶⣿⣷⣾⡀⠀⠀⠀⠀⠀⠀
⠀⡼⣹⣴⣿⡦⣟⣹⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡷⠿⠛⣤⣴⣿⣿⡷⣄⠀⠀⣴⣿⣿⣿⣿⣿⣿⣷⠀⠘⣆⣹⡋⠛⢹⣿⡷⠏⠀⢸⠁⠀⠀⠀⠀⠀⠀
⠀⡇⣿⢹⡌⣧⣽⢺⡁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣞⣁⠀⠀⠙⢿⠛⠿⠟⠈⠰⠀⢹⣿⣿⣿⣿⣿⣿⣿⡇⠀⢹⡋⢀⢰⡟⠁⠀⠀⠀⡄⠀⠀⠀⠀⠀⠀⠀
⠀⣟⣿⠟⠛⣯⡀⡌⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣼⣨⣿⣿⣶⠄⠀⠀⠀⠀⠀⠀⠀⣼⣿⣿⣿⣿⣿⣿⣿⠁⠀⠀⠳⣿⣾⣅⣀⣀⠀⠸⡇⠀⠀⠀⠀⠀⠀⠀
⠀⣏⣼⣦⣔⣚⣹⣇⢳⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⢿⣿⣽⣿⣦⡀⠀⠀⠀⠀⠀⣀⣤⡘⣛⢩⣯⣿⣿⣿⠏⠀⠀⠀⠀⠙⣷⠿⡉⠿⠿⠀⠹⡄⠀⠀⠀⠀⠀⠀
⠀⣿⡀⢻⣿⣿⡋⢸⡌⢧⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣾⡌⣾⣭⠉⢻⡷⠀⢠⡄⠀⠨⣿⣿⣤⣿⡟⠆⣏⣿⠋⠀⠀⠢⠀⠀⠀⠈⢣⠙⠳⠄⠀⠀⢳⠀⠀⠀⠀⠀⠀
⠀⣧⣷⣿⣿⣿⣿⣿⣟⣈⣦⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡟⣳⡏⣁⣐⣿⣿⣆⣨⣿⣹⣶⣫⣿⣝⣗⣲⣾⠟⠁⠀⠀⠀⠨⠀⠀⠀⠀⠀⢧⠀⠀⠀⠀⠈⢧⠀⠀⠀⠀⠀
⠀⢹⠉⣽⣯⣄⣀⣽⢻⣿⠞⢧⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠹⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡟⠋⢱⣿⠋⠀⠀⠀⠀⠀⠀⠄⠀⠀⠀⠀⠸⡌⠄⠀⠀⠀⠈⢧⠀⠀⠀⠀
⠀⠈⣿⣿⣿⣫⣿⣽⡿⠛⣶⢿⡟⠓⠢⠤⢤⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣠⠤⣀⠀⠀⠀⠙⣿⣿⣿⣿⣿⣿⣿⣿⡿⠋⠀⠀⢸⠃⠀⠀⠀⠀⠀⠁⠀⡀⠀⠀⠀⠀⠀⢧⠀⠀⠀⣀⠀⠈⢣⡀⠀⠀
⠀⠀⢸⡿⣿⣷⣽⣿⣿⣶⠾⠦⠆⠀⠀⠂⠀⠈⠉⠉⠓⠒⠺⠉⠉⠉⠉⠉⠉⠀⠀⡌⢳⣀⡀⠀⣷⢿⣿⡿⣿⠻⠟⠛⠈⢤⠈⠀⣻⢤⣀⡀⠀⣀⣀⣀⠀⠂⠀⠀⠀⠀⠀⢸⠀⠁⢀⠀⠀⠀⠀⢣⠀⠀
⠀⠀⠸⣿⣿⣿⣿⣿⣿⡏⠁⠀⡇⠀⠀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠄⠀⠹⡄⡀⠨⣽⡋⠁⢬⡿⠆⠁⠀⠀⠀⣁⠴⠊⠁⠀⢀⡊⠉⠁⠀⠈⠙⡟⠓⠒⠢⣤⣀⡈⡆⠀⠀⠀⣦⠀⠀⠈⢧⠀
⠀⠀⠀⠈⠻⢿⣿⣿⣿⣷⡄⠰⣷⠀⢀⣁⣀⠀⠀⠀⠀⠀⠂⠀⠀⠀⠀⣠⢶⣄⠀⠀⢱⡙⣄⠈⠧⠤⣀⣤⠤⠤⠖⠚⠉⠀⠀⢀⠴⠚⢿⡇⠀⠀⠀⠀⢀⠅⢀⣴⣶⣿⣿⠿⠿⡆⢀⡘⠹⣆⠀⠀⠈⣆
⠀⠀⠀⠀⠀⠀⠈⠙⠛⠿⣿⣆⣌⣇⠀⢿⠠⢭⡙⠒⠒⠤⠄⠀⡀⢀⡼⠁⠈⢙⣆⠀⠀⠉⠁⠀⠀⠀⢀⣀⣀⡄⠀⠀⠀⢠⡶⠉⠀⣰⢺⠃⠀⠀⠀⠠⠁⢠⣾⣿⣿⡿⠁⠀⠀⢳⡏⠀⣠⣿⡄⠀⠀⢸
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⢿⣿⡆⠈⢷⣄⠓⣦⠀⡀⢰⢲⠇⢸⠉⢳⡴⠋⠈⢧⠀⠀⠀⠀⣀⠈⢿⣃⢰⠃⢀⡤⠤⠽⢒⡞⠉⠁⢹⠀⠀⢸⠺⡤⢰⣿⣿⣿⣿⡇⠀⠀⠀⠘⣷⡾⠿⣿⣷⡄⠀⢸
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⢯⡉⣀⣨⣿⣷⣬⣦⠸⡜⣿⠀⠘⢳⡾⠿⣿⣿⡏⠀⠀⠀⡞⢠⠞⠛⠛⠋⠀⣼⣿⣷⣷⢸⣽⠀⠀⢸⠀⠀⠈⣷⢷⣸⣿⣿⣿⣿⣿⣀⡀⠀⠀⠙⠦⠤⣠⣤⣷⣤⡞
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠁⠀⠀⠙⠿⣝⢶⣧⡇⢀⠇⢰⠋⣳⡀⠉⠀⠀⣴⠿⡵⣄⣀⠀⠀⠀⠀⢷⣿⠿⠿⢓⣾⣤⣶⣾⠄⠀⠀⣻⢸⣿⣹⣿⣿⣿⣿⣷⣤⣴⣶⣾⣿⣿⣿⠟⠋⠁⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠳⣌⠀⢸⠒⠋⠘⢩⠃⠀⠀⣠⣿⠶⢣⣶⣶⣦⣄⠀⠀⠘⢛⣿⡿⠿⡷⠟⠋⡝⠀⠀⠀⡿⣼⣿⡿⣿⡏⢻⣿⣿⣿⡿⠿⠿⠛⠉⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⡇⢸⠀⠀⠀⠈⠀⠀⠀⢉⣿⢀⣿⡏⠹⠿⣿⠄⠀⠀⠀⠙⠚⣰⠀⠁⠈⡇⠀⠀⢰⡇⣿⣟⢠⣯⡀⣿⠞⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡇⢸⠀⠀⠀⠀⠀⠀⠀⣸⡿⢸⣿⠀⠀⢸⣿⠀⠀⠀⢀⠇⠀⡏⠁⠀⢸⠁⠀⠁⢸⡇⢿⣿⣿⣿⠟⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡇⢸⠀⠀⡀⠀⠀⠀⢀⣿⠇⣿⡇⠀⠀⣿⡇⠀⠀⠀⣸⠀⠀⢱⣀⠀⣸⠀⠀⠀⢸⠇⣳⢟⣭⠏⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡇⠀⠀⢀⡇⠀⠀⠀⣸⡿⠠⣿⣷⣤⣾⡿⠀⠀⠀⠀⣿⢧⡀⠀⠀⠳⡇⠀⠠⠀⢸⣀⡟⢣⠏⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡇⠀⠀⢸⠃⠀⠀⠀⢸⣇⠀⠈⣙⡟⠁⠀⠀⠀⠀⠀⠻⠦⠭⠷⠆⣼⠁⠀⠀⠀⢸⢹⡇⡎⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡇⠀⠀⠀⠀⠀⠀⠀⣸⠙⢢⠊⠁⠀⠀⠀⠀⠀⠀⠀⠀⠰⠀⠀⠀⢹⠀⠀⠀⠀⢸⣿⢳⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⠚⠃⠀⠀⠀⠀⠀⠀⠀⣠⣥⠀⠀⠀⠀⠀⠀⠀⠀⢸⣇⡞⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⠀⠀⠀⠀⠀⠀⠀⡇⠈⠳⢤⡀⠀⠀⠀⠀⠀⢸⣿⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢰⡇⠀⠀⠀⠀⠀⠀⢠⡄⠀⠀⠀⣹⠀⠀⠀⠀⠀⠀⠀⢧⣂⡢⠄⢹⠀⠀⠀⠀⠀⢸⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⠇⠀⠀⠀⠀⠀⠀⠀⠀⢰⠊⢉⡇⠀⠀⠀⠀⠀⠀⠀⠀⠠⠼⢤⣯⠀⠀⠀⠀⠀⣾⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⠓⠄⠀⠀⠀⠀⢀⠄⠀⠈⠧⣼⠁⠀⠀⠀⠀⠀⠀⠀⠀⡃⠀⣠⡾⠀⠀⠀⠀⠀⢿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⠀⠀⠀⠀⠀⠀⢸⣄⠀⠀⠀⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⣻⣴⠏⡇⠀⠀⠀⠀⠀⢸⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⠲⠀⠀⠀⠀⠀⠈⠛⠳⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⡞⠍⠁⠀⠒⡇⠀⠀⠀⠀⠀⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⠛⠑⠀⠀⠀⢸⠇⠀⠀⠀⠀⢀⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
gracias por el perrito cheems
EL PEMRRITO MALVADO

⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣀⠀⠀⠀⠀⢀⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣏⡽⠷⠾⠭⠍⠉⣯⣿⣶⢶⣄⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣰⠞⣿⣦⣴⣤⣀⠀⠉⣛⠹⣮⡇⣿⣿⢶⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⣴⠃⣴⣿⡯⠟⠀⠈⢀⠀⠹⡄⠙⣷⣿⣿⠶⣿⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣴⣿⡟⠀⣰⣬⣿⣾⠗⠀⠀⠐⢯⠛⣧⠀⢘⢷⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⣰⣿⣿⣿⡴⠀⠙⠉⠉⠈⠀⠀⠀⠀⠀⠀⣼⣶⠾⢾⣧⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⢀⣴⣿⣿⣿⠻⠁⠀⠀⠀⠀⠀⠀⠀⢀⠀⠀⣠⣿⠙⣄⠾⠿⣆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⢠⣿⣿⣿⡿⠥⠀⠀⢀⣴⠀⠀⠀⠀⠀⣨⠀⠴⠋⠀⠘⠁⠀⣠⣿⣆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠈⠙⠿⣿⣧⣤⣯⣿⡿⠋⠀⠀⠀⣤⠞⠀⠀⠀⠀⠀⠀⠀⠀⠟⠁⠘⢦⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⢿⠛⠁⠀⠀⠀⠀⠀⣿⠀⠀⠀⠀⢀⣴⠀⠀⠀⠀⠀⠀⠀⢳⣄⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⠀⠀⠀⠀⠀⠀⠀⠹⡦⠀⣀⣴⠏⠀⠀⠀⠀⠀⠀⠀⣀⣿⠙⢦⡀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣄⠀⠀⠀⠀⠀⠀⠀⠳⠖⠉⠀⠀⠀⠀⠀⠀⠁⠀⣴⠟⠩⠀⢠⣿⢦⡀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣼⠋⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣤⠀⠿⠀⠁⠀⠀⢀⣸⡯⠙⢷⡀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣀⠤⠐⠈⠀⠀⠀⠀⠀⠀⠀⣠⠟⠃⠀⢸⣇⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⢖⠀⠀⠀⠀⠀⠀⠀⠐⠚⠉⠀⠀⠀⠀⡴⡋⠀⠀⠀⠀⣦⡏⠀⠀⠀⣾⣿⡄⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠸⣿⠷⣦⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠠⢪⡞⠁⠀⠀⠀⠀⠁⠀⠀⠀⣶⠏⣿⣿⡄⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢿⡦⡌⠳⠤⠀⠀⠀⠀⠀⠀⠀⠀⢀⣰⠏⠀⠀⠀⠀⠀⠀⠀⠀⠀⠐⠋⠀⣻⣹⣿⡄
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠰⠋⠀⠀⠀⠀⠀⠀⢀⣾⠀⠀⠀⠀⣾⠀⠹⢿⣿⣷
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⠀⠀⠀⠀⣶⠀⠀⠀⠀⠀⣆⠀⠟⠀⠀⠀⠀⠀⡾⠃⠀⢠⡠⠀⢠⣾⣾⣿⣿⡇
⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣼⡿⠀⠀⠀⣰⣿⣀⠀⠀⠀⠀⢹⡤⡄⠀⠀⠀⠀⣸⣿⡀⣶⣶⣷⣶⣿⣿⣿⣿⡟⠁
⠀⠀⠀⠀⠀⠀⣀⡠⠶⠋⣸⣗⠀⠀⢀⣿⣻⣿⡦⠤⠤⠤⠿⣷⠇⠀⠀⠀⢠⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠏⠀⠀
⠀⣀⡴⠖⠋⠉⠉⢀⣀⡴⣿⡏⠀⢀⣸⡟⠛⠀⠀⠀⠀⠀⠀⣿⠀⠀⠀⠀⣾⣿⣿⣿⣿⣿⣿⣿⣿⠟⠁⠀⠀⠀
⠘⢿⣷⣤⡤⠶⠚⠋⠁⢀⡟⠀⠀⣾⣿⣁⣀⠀⠀⠀⠀⠀⠀⣿⠀⠀⢀⣼⣿⣿⣿⣿⣿⣿⠿⠛⠁⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⢀⣀⠴⢞⡿⠀⠀⢴⡿⠋⠉⠉⠉⠛⠲⠶⠤⣤⣿⠀⠀⢰⣿⣿⣿⠿⠟⠋⠁⠀⠀⠀⠀⠀⠀⠀⠀
⠀⢀⣠⣶⡊⠉⢀⣠⠞⠁⠀⢀⡾⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⠀⠀⢸⣯⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠈⠉⠻⠶⣶⡟⠃⡴⠀⢀⡞⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⠏⠀⠀⢸⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠠⣿⣄⣾⣄⡷⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡿⠀⠀⠀⢸⡏⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠈⠁⠉⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣼⡁⠀⠀⠀⢸⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣏⡇⠀⡶⠀⣸⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠹⣇⣴⠷⠞⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀

*/
#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// #include <ext/rope>
#define int ll
#define mp				make_pair
#define pb				push_back
#define all(a)			(a).begin(), (a).end()
#define sz(a)			(int)a.size()
#define eq(a, b)     	(fabs(a - b) < EPS)
#define md(a, b)		((a) % b + b) % b
#define mod(a)			md(a, MOD)
#define _max(a, b) ((a) > (b) ? (a) : (b))
#define srt(a)			sort(all(a))
#define mem(a, h)		memset(a, (h), sizeof(a))
#define f 				first
#define s 				second
#define forn(i, n)			for(int i = 0; i < n; i++)
#define fore(i, b, e)	for(int i = b; i < e; i++)
#define forg(i, b, e, m)	for(int i = b; i < e; i+=m)
#define index	int mid = (b + e) / 2, l = node * 2 + 1, r = l + 1;
#define DBG(x) cerr<<#x<<" = "<<(x)<<endl
#define RAYA cout<<"=============================="<<'\n'
// int in(){int r=0,c;for(c=getchar();c<=32;c=getchar());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar());return r;}


using namespace std;
// using namespace __gnu_pbds;
// using namespace __gnu_cxx;

// #pragma GCC target ("avx2")
// #pragma GCC optimization ("O3")
// #pragma GCC optimization ("unroll-loops")

typedef long long 		ll;
typedef long double ld;	
typedef unsigned long long 		ull;
typedef pair<int, int>  ii;
typedef pair<pair<int, int>, int> iii;
typedef vector<int>     vi;
typedef vector<ii>      vii;
typedef vector<ll>      vll;
// typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
// find_by_order kth largest  order_of_key <
// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// rng
const int tam = 200010;
const int MOD = 1000000007;
const int MOD1 = 998244353;
const double DINF=1e100;
const double EPS = 1e-9;
const double PI = acos(-1); 
vi ar(100);
int dp[51][51][51][51];
int pot[51];
int f(int ew, int ow, int eb, int ob)
{
    if(ew + ow + eb + ob == 0) return 1;
    int &res = dp[ew][ow][eb][ob];
    if(res != -1) return res;
    res = 0;
    int i = ew + ow + eb + ob - 1;
    if(ar[i] != 1)
    {
        if(ew > 0)
            res = (res + f(ew - 1, ow, eb, ob) * (ob ? pot[ob - 1]: 0)) % MOD;
        if(ow > 0)
            res = (res + f(ew, ow - 1, eb, ob) * (ob ? pot[ob - 1] : 1)) % MOD;
        res = res * pot[ew + ow + eb - 1] % MOD;
    }

    if(ar[i] != 0)
    {
        if(eb > 0)
            res = (res + f(ew, ow, eb - 1, ob) * pot[ew + eb + ob - 1] % MOD * (ow ? pot[ow - 1] : 0)) % MOD;
        if(ob > 0)
            res = (res + f(ew, ow, eb, ob - 1) * pot[ew + eb + ob - 1] % MOD * (ow ? pot[ow - 1] : 1)) % MOD;
    }
    return res;
}
signed main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen("asd.txt", "r", stdin);
	// freopen("qwe.txt", "w", stdout);
    pot[0] = 1;
    fore(i, 1, 51) pot[i] = pot[i - 1] * 2 % MOD;
    mem(dp, -1);
	int n, p;
    cin>>n>>p;
    fore(i, 0, n) cin>>ar[i];
    int res = 0;
    fore(i, 0, n + 1)
        fore(j, i, n + 1)
            fore(k, j, n + 1)
            {
                int ew = i, ow = j - i, eb = k - j, ob = n - k;
                if((ow + ob) % 2 == p)
                {
                    int raza = f(ew, ow, eb, ob);
                    res = (res + raza) % MOD;
                }
            }
    cout<<res<<'\n';
	return 0;
}
// Se vuelve más fácil,
// cada día es un poco más fácil, pero tienes que hacerlo cada día,
// es la parte difícil, pero se vuelve más fácil.
// Crecer duele.
// La única manera de pasar esa barrera es pasandola.
// efe no más.
// Si no vá por todo, andá pa' allá bobo.
// No sirve de nada hacer sacrificios si no tienes disciplina.
// Cae 7 veces, levántate 8.
// LA DISCIPLINA es el puente entre tus metas y tus logros.
// Take a sad song and make it better