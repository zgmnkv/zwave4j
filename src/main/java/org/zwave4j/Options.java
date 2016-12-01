package org.zwave4j;

import java.util.concurrent.atomic.AtomicReference;

/**
 * @author zagumennikov
 */
public class Options {

    private static Options instance;

    public static synchronized Options create(String configPath, String userPath, String commandLine) {
        if (instance == null) {
            createNativeOptions(configPath, userPath, commandLine);
            instance = new Options();
        }
        return instance;
    }

    public static Options get() {
        return instance;
    }

    public static boolean destroy() {
		instance	= null;
        return destroyNativeOptions();
    }

    private static native void createNativeOptions(String configPath, String userPath, String commandLine);

    private static native boolean destroyNativeOptions();


    public native boolean lock();

    public native boolean addOptionBool(String name, boolean defaultValue);

    public native boolean addOptionInt(String name, int defaultValue);

    public native boolean addOptionString(String name, String defaultValue, boolean append);

    public native boolean getOptionAsBool(String name, AtomicReference<Boolean> value);

    public native boolean getOptionAsInt(String name, AtomicReference<Integer> value);

    public native boolean getOptionAsString(String name, AtomicReference<String> value);

    public native OptionType getOptionType(String name);

    public native boolean areLocked();
}
