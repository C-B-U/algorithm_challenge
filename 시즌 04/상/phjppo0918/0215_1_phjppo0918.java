package org.example.bruteforce.bj4920;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;

public class Main {
    static int boardSize;
    static int[][] board;
    static int max;
    static int[][][][] block = {
            {
                    {
                            {0, 0, 0, 0},
                            {0, 1, 2, 3}
                    },
                    {
                            {0, 1, 2, 3},
                            {0, 0, 0, 0}
                    }
            },
            {
                    {
                            {0, 0, 1, 1},
                            {0, 1, 1, 2}
                    },
                    {
                            {0, 1, 1, 2},
                            {0, 0, -1, -1}
                    }
            },
            {
                    {
                            {0, 0, 0, 1},
                            {0, 1, 2, 2}
                    },
                    {
                            {0, 1, 2, 2},
                            {0, 0, 0, -1}
                    },
                    {
                            {0, 1, 1, 1},
                            {0, 0, 1, 2}
                    },
                    {
                            {0, 0, 1, 2},
                            {0, 1, 0, 0}
                    }
            },
            {
                    {
                            {0, 1, 1, 1},
                            {0, -1, 0, 1}
                    },
                    {
                            {0, 1, 1, 2},
                            {0, 0, 1, 0}
                    },
                    {
                            {0, 0, 0, 1},
                            {0, 1, 2, 1}
                    },
                    {
                            {0, 1, 1, 2},
                            {0, -1, 0, 0}
                    }
            },
            {
                    {
                            {0, 0, 1, 1},
                            {0, 1, 1, 0}
                    }
            }
    };


    public static void main(String[] args) throws Exception {
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringBuilder sb = new StringBuilder();

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int round = 1;

        while ((boardSize = Integer.parseInt(br.readLine().trim())) != 0) {
            board = new int[boardSize][boardSize];
            max = Integer.MIN_VALUE;

            for (int i = 0; i < boardSize; i++) {
                board[i] = Arrays.stream(br.readLine().trim().split(" ")).filter(s -> !s.isBlank()).mapToInt(Integer::parseInt).toArray();
            }

            for (int i = 0; i < boardSize; i++) {
                for (int j = 0; j < boardSize; j++) {
                    for (int k = 0; k < 5; k++) {
                        for (int l = 0; l < block[k].length; l++) {
                            int sum = 0;
                            boolean isSafe = true;
                            for (int c = 0; c < 4; c++) {
                                int x = block[k][l][0][c];
                                int y = block[k][l][1][c];
                                if (!checkSafe(i + x, j + y)) {
                                    isSafe = false;
                                    break;
                                }
                                sum += board[i + x][j + y];
                            }
                            if (isSafe) {
                                max = Math.max(max, sum);
                            }
                        }
                    }
                }
            }
            sb.append(round).append(". ").append(max).append("\n");
            round++;
        }

        bw.write(sb.toString());

        bw.flush();
        br.close();
        bw.close();
    }

    static boolean checkSafe(int x, int y) {
        if (x < 0 || x >= boardSize || y < 0 || y >= boardSize) return false;
        return true;
    }

    static int getValue(int x, int y) {
        return board[x][y];
    }
}
