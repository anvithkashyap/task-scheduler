#include <gtk/gtk.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

GtkWidget *cpu_util_bar;

void update_cpu_utilization() {
    // Simulated CPU utilization (replace with actual code to get CPU usage)
    static double cpu_usage = 0.0;
    cpu_usage += 0.1; // Simulate CPU usage increment
    
    if (cpu_usage > 1.0)
        cpu_usage = 0.0;
    
    gtk_progress_bar_set_fraction(GTK_PROGRESS_BAR(cpu_util_bar), cpu_usage);
    gtk_widget_queue_draw(cpu_util_bar);
    
    // Schedule the next update
    g_timeout_add_seconds(1, (GSourceFunc)update_cpu_utilization, NULL);
}

static void activate(GtkApplication *app, gpointer user_data) {
    GtkWidget *window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), "CPU Utilization Monitor");
    gtk_window_set_default_size(GTK_WINDOW(window), 400, 100);
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    cpu_util_bar = gtk_progress_bar_new();
    gtk_container_add(GTK_CONTAINER(window), cpu_util_bar);
    gtk_progress_bar_set_show_text(GTK_PROGRESS_BAR(cpu_util_bar), TRUE);

    // Start updating CPU utilization
    update_cpu_utilization();

    gtk_widget_show_all(window);
}

int main(int argc, char **argv) {
    GtkApplication *app;
    int status;

    app = gtk_application_new("org.example.cpu_utilization", G_APPLICATION_FLAGS_NONE);
    g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
    status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);

    return status;
}
