package com.example.clientcan;

import static java.lang.Math.cos;
import static java.lang.Math.sin;

import android.content.Context;
import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.Paint;
import android.util.AttributeSet;
import android.view.View;

public class CircleView extends View {
    private Paint circlePaint;
    private Paint linePaint;
    private int angle;

    public CircleView(Context context, AttributeSet attrs) {
        super(context, attrs);
        init();
    }

    private void init() {
        angle = 0;
        circlePaint = new Paint();
        circlePaint.setColor(Color.rgb(120, 120, 120));
        circlePaint.setStyle(Paint.Style.STROKE);
        circlePaint.setStrokeWidth(3);
        linePaint = new Paint();
        linePaint.setColor(Color.rgb(62, 124, 120));
        linePaint.setStrokeWidth(2);
    }

    @Override
    protected void onDraw(Canvas canvas) {
        super.onDraw(canvas);
        int centerX = getWidth() / 2;
        int centerY = getHeight() / 2;
        int radius = Math.min(centerX, centerY) - 3;
        canvas.drawCircle(centerX, centerY, radius, circlePaint);
        float x = (float) (centerX + radius * cos((angle * 3.14159) / 180));
        float y = (float) (centerY + radius * sin((angle * 3.14159) / 180));
        canvas.drawLine(centerX, centerY, x, y, linePaint);
    }

    // Method to update the flag and trigger a redraw
    public void setDrawLine(int _angle) {
        this.angle = _angle;
        this.invalidate(); // Trigger a redraw
    }
}
