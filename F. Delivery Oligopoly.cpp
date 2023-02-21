// https://codeforces.com/contest/1155/problem/F
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
vi g[20];
int dp[1<<14];
int can[14][14][1<<14];
int go[14][14][1<<14];
int mat[20][20];
vi maskus[1<<14];
int toto;
int f(int mask)
{
    if(mask == toto) return 0;
    if(dp[mask] != -1) return dp[mask];
    dp[mask] = MOD;
    int anti = toto ^ mask;
    fore(i, 0, sz(maskus[mask]))
        fore(j, i, sz(maskus[mask]))
            for(int k = anti; k; k = (k - 1) & anti)
                if(can[maskus[mask][i]][maskus[mask][j]][k])
                    dp[mask] = min(dp[mask], f(mask | k) + __builtin_popcount(k) + 1);
    return dp[mask];
}
signed main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen("asd.txt", "r", stdin);
	// freopen("qwe.txt", "w", stdout);
	int n, m;
    cin>>n>>m;
    forn(i, m)
    {
        int a, b;
        cin>>a>>b;
        a--, b--;
        g[a].pb(b);
        g[b].pb(a);
        can[a][b][0] = can[b][a][0] = 1;
        mat[a][b] = mat[b][a] = 1;
    }
    toto = (1<<n) - 1;
    mem(dp, -1);
    fore(i, 0, 1<<n)
        fore(j, 0, n)
            if(i & 1 << j)
                maskus[i].pb(j);
    fore(i, 1, n)
        fore(j, 0, 1<<n)
            if(__builtin_popcount(j) == i)
            {
                fore(i, 0, n)
                    if(~j & (1<<i))
                        fore(k, 0, n)
                            if(~j & (1<<k))
                            {
                                if(i != k)
                                {
                                    fore(l, 0, n)
                                        if((j & 1<< l) && can[i][l][j ^ (1<<l)] && mat[l][k])
                                            can[i][k][j] = 1, go[i][k][j] = l;
                                }
                                else
                                {
                                    fore(l, 0, n)
                                        if((j & 1<< l) && can[i][l][j ^ (1<<l)] && mat[l][k] && __builtin_popcount(j) > 1)
                                            can[i][k][j] = 1, go[i][k][j] = l;
                                }
                            }
            }

    auto print_pato = [&](int a, int b, int mask)
    {
        // cout<<"$$$\n";
        while(mask)
        {
            int c = go[a][b][mask];
            cout<<b + 1<<' '<<c + 1<<'\n';
            // cout<<'%'<<a<<' '<<b<<' '<<c<<'\n';
            mask ^= 1<<c;
            b = c;
        }
        cout<<a + 1<<' '<<b + 1<<'\n';
    };
    ii res = {MOD, -1};
    forn(i, n)
    {
        // cout<<i<<' '<<f(1<<i)<<'\n';
        res = min(res, {f(1<<i), 1<<i});
    }
    int mask = res.s;
    cout<<res.f<<'\n';
    // cout<<res.s<<'\n';
    while(mask != toto)
    {
        pair<ii, ii> mimi = {{MOD, 0}, {0, 0}};
        int anti = toto ^ mask;
        fore(i, 0, sz(maskus[mask]))
            fore(j, i, sz(maskus[mask]))
                for(int k = anti; k; k = (k - 1) & anti)
                    if(can[maskus[mask][i]][maskus[mask][j]][k])
                        mimi = min(mimi, {{dp[mask | k] + __builtin_popcount(k) + 1, k}, {maskus[mask][i], maskus[mask][j]}});
        print_pato(mimi.s.f, mimi.s.s, mimi.f.s);
        mask |= mimi.f.s;
    }
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