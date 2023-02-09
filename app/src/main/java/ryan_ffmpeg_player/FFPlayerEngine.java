package ryan_ffmpeg_player;

public class FFPlayerEngine {
    public native static void init(String filePath);
    public native static void unInit();

    public native static void streamOpen(String input, String output);
}
