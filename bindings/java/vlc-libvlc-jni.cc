/*****************************************************************************
 * JVLC.java: JNI interface for vlc Java Bindings
 *****************************************************************************
 * Copyright (C) 1998-2006 the VideoLAN team
 *
 * Authors: Filippo Carone <filippo@carone.org>
 *
 * $Id$
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111, USA.
 *****************************************************************************/

/* These are a must*/
#include <jni.h>
#include <vlc/libvlc.h>

#include <stdio.h>  // for printf
#include <stdlib.h> // for calloc
#include <string.h> // for strcmp


/* JVLC internal imports, generated by gcjh */
#include "org_videolan_jvlc_JVLC.h"
#include "org_videolan_jvlc_Playlist.h"

jlong getClassInstance (JNIEnv *env, jobject _this);
jlong getPlaylistInstance (JNIEnv *env, jobject _this);

JNIEXPORT jlong JNICALL Java_org_videolan_jvlc_JVLC_createInstance__ (JNIEnv *env, jobject _this) {

    // res is the pointer to libvlc_instance_t
    long res;
    libvlc_exception_t *exception = ( libvlc_exception_t * ) malloc( sizeof( libvlc_exception_t ));

    libvlc_exception_init( exception );
    res = ( long ) libvlc_new( 0, NULL, exception );

    if ( libvlc_exception_raised( exception )) 
    {
        ///\TODO: raise java exception
        printf("%s\n", libvlc_exception_get_message( exception ));
    }

    free( exception );

    return res;
}

JNIEXPORT jlong JNICALL Java_org_videolan_jvlc_JVLC_createInstance___3Ljava_lang_String_2 (JNIEnv *env, jobject _this, jobjectArray args) {

    long res;
    int argc;
    const char **argv;

    libvlc_exception_t *exception = ( libvlc_exception_t * ) malloc( sizeof( libvlc_exception_t ) );

    libvlc_exception_init( exception );
  
    argc = (int) env->GetArrayLength((jarray) args);
    argv = (const char **) malloc(argc * sizeof(char*));
    for (int i = 0; i < argc; i++) {
        argv[i] = env->GetStringUTFChars((jstring) env->GetObjectArrayElement(args, i),
                                         0
        );
    }

    res = (long) libvlc_new(argc, (char**) argv, exception );

    free( exception );
    free( argv );

    return res;

}

/*
 * Audio native functions
 */

JNIEXPORT jboolean JNICALL Java_org_videolan_jvlc_JVLC__1getMute (JNIEnv *env, jobject _this) 
{
    // res is the final result
    jboolean res;
    long instance = 0;
    
    libvlc_exception_t *exception = ( libvlc_exception_t * ) malloc( sizeof( libvlc_exception_t ));

    libvlc_exception_init( exception );

    instance = getPlaylistInstance( env, _this );
   
    res = (jboolean) libvlc_audio_get_mute( ( libvlc_instance_t * ) instance, exception );
    
    if ( libvlc_exception_raised( exception )) 
    {
        ///\TODO: raise java exception
        printf("%s\n", libvlc_exception_get_message( exception ));
    }

    free( exception );

    return res;
    
}

JNIEXPORT void JNICALL Java_org_videolan_jvlc_JVLC__1setMute (JNIEnv *env, jobject _this, jboolean value) 
{
    long instance = 0;
    
    libvlc_exception_t *exception = ( libvlc_exception_t * ) malloc( sizeof( libvlc_exception_t ));

    libvlc_exception_init( exception );

    instance = getPlaylistInstance( env, _this );

    libvlc_audio_set_mute( ( libvlc_instance_t * ) instance, value, exception );
    
    if ( libvlc_exception_raised( exception )) 
    {
        ///\TODO: raise java exception
        printf("%s\n", libvlc_exception_get_message( exception ));
    }

    free( exception );
}

JNIEXPORT void JNICALL Java_org_videolan_jvlc_JVLC__1toggleMute (JNIEnv *env, jobject _this) 
{

    long instance = 0;
    
    libvlc_exception_t *exception = ( libvlc_exception_t * ) malloc( sizeof( libvlc_exception_t ));

    libvlc_exception_init( exception );

    instance = getPlaylistInstance( env, _this );

    ///\TODO: NO, this is not what we want.
    libvlc_audio_get_mute( ( libvlc_instance_t * ) instance, exception );
    
    if ( libvlc_exception_raised( exception )) 
    {
        ///\TODO: raise java exception
        printf("%s\n", libvlc_exception_get_message( exception ));
    }

    free( exception );
}

JNIEXPORT jint JNICALL Java_org_videolan_jvlc_JVLC__1getVolume (JNIEnv *env, jobject _this)
{

    // res is the final result
    jboolean res;
    long instance = 0;
    
    libvlc_exception_t *exception = ( libvlc_exception_t * ) malloc( sizeof( libvlc_exception_t ));

    libvlc_exception_init( exception );

    instance = getPlaylistInstance( env, _this );

    
    res = (jboolean) libvlc_audio_get_mute( ( libvlc_instance_t * ) instance, exception );
    
    if ( libvlc_exception_raised( exception )) 
    {
        ///\TODO: raise java exception
        printf("%s\n", libvlc_exception_get_message( exception ));
    }

    free( exception );

    return res;
    
}

JNIEXPORT jint JNICALL Java_org_videolan_jvlc_JVLC__1getVolume (JNIEnv *env, jobject _this, jboolean value) 
{
    jint res = 0;
    long instance = 0;
    
    libvlc_exception_t *exception = ( libvlc_exception_t * ) malloc( sizeof( libvlc_exception_t ));

    libvlc_exception_init( exception );

    instance = getPlaylistInstance( env, _this );

    res = libvlc_audio_get_volume( ( libvlc_instance_t * ) instance, exception );
    
    if ( libvlc_exception_raised( exception )) 
    {
        ///\TODO: raise java exception
        printf("%s\n", libvlc_exception_get_message( exception ));
    }

    free( exception );

    return res;
}

JNIEXPORT void JNICALL Java_org_videolan_jvlc_JVLC__1setVolume (JNIEnv *env, jobject _this, jint volume) 
{
    long instance = 0;
    
    libvlc_exception_t *exception = ( libvlc_exception_t * ) malloc( sizeof( libvlc_exception_t ));

    libvlc_exception_init( exception );

    instance = getPlaylistInstance( env, _this );

    libvlc_audio_set_volume( ( libvlc_instance_t * ) instance, volume, exception );
    
    if ( libvlc_exception_raised( exception )) 
    {
        ///\TODO: raise java exception
        printf("%s\n", libvlc_exception_get_message( exception ));
    }

    free( exception );
}



/*
 * Video native functions
 */
JNIEXPORT void JNICALL Java_org_videolan_jvlc_JVLC__1toggleFullscreen (JNIEnv *env, jobject _this) 
{
    long instance = 0;
    libvlc_input_t *input;
    libvlc_exception_t *exception = ( libvlc_exception_t * ) malloc( sizeof( libvlc_exception_t ));

    libvlc_exception_init( exception );

    instance = getPlaylistInstance( env, _this );

    input = libvlc_playlist_get_input( ( libvlc_instance_t *) instance, exception );

    
    libvlc_toggle_fullscreen( input, exception );
    
    if ( libvlc_exception_raised( exception )) 
    {
        ///\TODO: raise java exception
        printf("%s\n", libvlc_exception_get_message( exception ));
    }

    free( exception );
}

JNIEXPORT void JNICALL Java_org_videolan_jvlc_JVLC__1setFullscreen (JNIEnv *env, jobject _this, jboolean value)
{
    long instance = 0;
    libvlc_input_t *input;
    
    libvlc_exception_t *exception = ( libvlc_exception_t * ) malloc( sizeof( libvlc_exception_t ));

    libvlc_exception_init( exception );

    instance = getPlaylistInstance( env, _this );

    input = libvlc_playlist_get_input( ( libvlc_instance_t *) instance, exception );
    libvlc_set_fullscreen( input, value, exception );
    
    if ( libvlc_exception_raised( exception )) 
    {
        ///\TODO: raise java exception
        printf("%s\n", libvlc_exception_get_message( exception ));
    }

    free( exception );
}

JNIEXPORT jboolean JNICALL Java_org_videolan_jvlc_JVLC__1getFullscreen (JNIEnv *env, jobject _this)
{
    int res = 0;
    libvlc_input_t *input;
    long instance = 0;
    
    libvlc_exception_t *exception = ( libvlc_exception_t * ) malloc( sizeof( libvlc_exception_t ));

    libvlc_exception_init( exception );

    instance = getPlaylistInstance( env, _this );
    input = libvlc_playlist_get_input( ( libvlc_instance_t *) instance, exception );

    res = libvlc_get_fullscreen( input, exception );
    
    if ( libvlc_exception_raised( exception )) 
    {
        ///\TODO: raise java exception
        printf("%s\n", libvlc_exception_get_message( exception ));
    }

    free( exception );

    return res;
}




/*
 * Playlist native functions
 */

JNIEXPORT jint JNICALL Java_org_videolan_jvlc_Playlist__1playlist_1add (JNIEnv *env, jobject _this, jstring uri, jstring name) {
    long instance = 0;
    int res = 0;
    const char* psz_uri  = env->GetStringUTFChars( uri, 0 );
    const char* psz_name = env->GetStringUTFChars( name, 0 );
    libvlc_exception_t *exception = (libvlc_exception_t *) malloc( sizeof( libvlc_exception_t ));

    libvlc_exception_init( exception );

    instance = getPlaylistInstance( env, _this );

    res = libvlc_playlist_add( (libvlc_instance_t*) instance, psz_uri, psz_name, exception );
  
    /// \todo check exceptions

    /* free resources */
    free(exception);
    if (psz_uri != NULL) {
        env->ReleaseStringUTFChars( uri, psz_uri );
    }

    if (psz_name != NULL) {
        env->ReleaseStringUTFChars( name, psz_name );
    }

    return res;
}

JNIEXPORT void JNICALL Java_org_videolan_jvlc_Playlist__1play (JNIEnv *env, jobject _this, jint id, jobjectArray options) {

    long instance = 0;
    int i_options = 0;
    char** ppsz_options = NULL;
    instance = getPlaylistInstance( env, _this );
    libvlc_exception_t *exception = ( libvlc_exception_t * ) malloc( sizeof( libvlc_exception_t ));

    libvlc_exception_init( exception );

    if ( options != NULL ) ;
    /// \TODO: parse options 

    libvlc_playlist_play( ( libvlc_instance_t* ) instance, id, i_options, ppsz_options, exception );

    free( exception );
    return;
}


JNIEXPORT void JNICALL Java_org_videolan_jvlc_Playlist__1pause (JNIEnv *env, jobject _this) {
    long instance = 0;
    libvlc_exception_t *exception = ( libvlc_exception_t * ) malloc( sizeof( libvlc_exception_t ) );

    libvlc_exception_init( exception );
    instance = getPlaylistInstance( env, _this );
  
    libvlc_playlist_pause( ( libvlc_instance_t* ) instance, exception );

    free( exception );
    return;
}

JNIEXPORT void JNICALL Java_org_videolan_jvlc_Playlist__1stop (JNIEnv *env, jobject _this) {
    long instance = 0;
    libvlc_exception_t *exception = ( libvlc_exception_t * ) malloc( sizeof( libvlc_exception_t ) );

    libvlc_exception_init( exception );
    instance = getPlaylistInstance( env, _this );
    libvlc_playlist_stop( ( libvlc_instance_t* ) instance, exception );

    free( exception );
    return;
  
}

JNIEXPORT void JNICALL Java_org_videolan_jvlc_Playlist__1next (JNIEnv *env, jobject _this) {
    long instance = 0;
    libvlc_exception_t *exception = ( libvlc_exception_t * ) malloc( sizeof( libvlc_exception_t ) );

    libvlc_exception_init( exception );
    instance = getPlaylistInstance( env, _this );
    libvlc_playlist_next( ( libvlc_instance_t* ) instance, exception );

    free( exception );
    return;

}

JNIEXPORT void JNICALL Java_org_videolan_jvlc_Playlist__1prev (JNIEnv *env, jobject _this) {
    long instance = 0;
    libvlc_exception_t *exception = ( libvlc_exception_t * ) malloc( sizeof( libvlc_exception_t ));

    libvlc_exception_init( exception );
    instance = getPlaylistInstance( env, _this );
    libvlc_playlist_prev( (libvlc_instance_t*) instance, exception );

    free( exception );
    return;
}

JNIEXPORT void JNICALL Java_org_videolan_jvlc_Playlist__1clear (JNIEnv *env, jobject _this) {
    long instance = 0;
    libvlc_exception_t *exception = (libvlc_exception_t *) malloc( sizeof( libvlc_exception_t ));

    libvlc_exception_init( exception );
    instance = getPlaylistInstance( env, _this );
    libvlc_playlist_clear( (libvlc_instance_t*) instance, exception );

    free( exception );
    return;
}

JNIEXPORT jint JNICALL Java_org_videolan_jvlc_Playlist__1itemsCount (JNIEnv *env, jobject _this) {
    long instance = 0;
    int res = 0;
    libvlc_exception_t *exception = (libvlc_exception_t *) malloc( sizeof( libvlc_exception_t ));

    libvlc_exception_init( exception );
    instance = getPlaylistInstance( env, _this );
    res = libvlc_playlist_items_count( (libvlc_instance_t*) instance, exception );

    free( exception );
    return res;

}

JNIEXPORT jint JNICALL Java_org_videolan_jvlc_Playlist__1isPlaying (JNIEnv *env, jobject _this) {
    long instance = 0;
    int res = 0;
    libvlc_exception_t *exception = (libvlc_exception_t *) malloc( sizeof( libvlc_exception_t ));

    libvlc_exception_init( exception );
    instance = getPlaylistInstance( env, _this );
    res = libvlc_playlist_isplaying( (libvlc_instance_t*) instance, exception );

    free( exception );
    return res;

}


/*
 * Utility functions
 */
jlong getClassInstance (JNIEnv *env, jobject _this) {
    /* get the id field of object */
    jclass    cls   = env->GetObjectClass(_this);
    jmethodID mid   = env->GetMethodID(cls, "getInstance", "()J");
    jlong     field = env->CallLongMethod(_this, mid);
    return field;
}

jlong getPlaylistInstance (JNIEnv *env, jobject _this) {
    /* get the instance field of object */
    jclass    cls   = env->GetObjectClass(_this);
    jmethodID mid   = env->GetMethodID(cls, "getInstance", "()J");
    jlong     field = env->CallLongMethod(_this, mid);
    return field;
}
