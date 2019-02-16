package com.example.android.pets;

import android.content.Context;
import android.database.Cursor;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.CursorAdapter;
import android.widget.TextView;

import com.example.android.pets.data.PetContract;

public class PetCurAdapter extends CursorAdapter {

    public PetCurAdapter(Context context, Cursor c) {
        super(context, c, 0 /* flags */);
    }

    @Override
    public View newView(Context context, Cursor cursor, ViewGroup parent) {
        return LayoutInflater.from(context).inflate(R.layout.list_item, parent, false);
    }

    // The bindView method is used to bind all data to a given view
    // such as setting the text on a TextView.
    @Override
    public void bindView(View view, Context context, Cursor cursor) {
        // Find fields to populate in inflated template
        TextView name = (TextView) view.findViewById(R.id.name);
        TextView breed = (TextView) view.findViewById(R.id.breed);
        // Extract properties from cursor
        int n = cursor.getColumnIndex(PetContract.PetEntry.COLUMN_PET_NAME);
        int b = cursor.getColumnIndex(PetContract.PetEntry.COLUMN_PET_BREED);
        // Populate fields with extracted properties
        name.setText(cursor.getString(n));
        breed.setText(cursor.getString(b));
    }
}

