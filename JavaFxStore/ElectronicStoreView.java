import javafx.collections.FXCollections;
import javafx.collections.ObservableArray;
import javafx.collections.ObservableList;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.scene.control.*;
import javafx.scene.control.Label;
import javafx.scene.control.TextField;
import javafx.scene.input.MouseEvent;
import javafx.scene.layout.BorderPane;
import javafx.scene.layout.Pane;

import javax.swing.*;
import java.awt.*;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.Map;

public class ElectronicStoreView extends Pane{

    private ListView<String>    pList, sList, cList;
    private TextField amountPerSale, saleNumText, revenueText;
    private DVDButtonPane       buttonPane;

    private int numSales;
    private double revenue;
    private ObservableList<String> stockList, cartList;
    public ListView<String> getPopularList() { return pList; }
    public ListView<String> getStockList() { return sList; }
    public ListView<String> getCartList() { return cList; }
    public DVDButtonPane getButtonPane() { return buttonPane; }


    public ElectronicStoreView(){

        Label label1 = new Label("Store Summary:");
        label1.relocate(40, 35);
        Label label2 = new Label("Store Stock:");
        label2.relocate(220, 35);
        Label label3 = new Label("Current Cart:");
        label3.relocate(550, 35);
        Label label4 = new Label("# Sales:");
        label4.relocate(10, 60);
        Label label5 = new Label("Revenue:");
        label5.relocate(10, 95);
        Label label6 = new Label("$/Sale:");
        label6.relocate(10, 125);
        Label label7 = new Label("Most Popular Items:");
        label7.relocate(20, 170);

        saleNumText = new TextField();
        saleNumText.relocate(85,60);
        saleNumText.setPrefSize(95,25);

        revenueText = new TextField();
        revenueText.relocate(85,95);
        revenueText.setPrefSize(95,25);

        amountPerSale = new TextField();
        amountPerSale.relocate(85,125);
        amountPerSale.setPrefSize(95,25);

        sList = new ListView<String>();
        sList.relocate(190, 65);
        sList.setPrefSize(290,270);

        cList = new ListView<String>();
        cList.relocate(490, 65);
        cList.setPrefSize(290,270);

        pList = new ListView<String>();
        pList.relocate(10, 190);
        pList.setPrefSize(170,145);

        buttonPane = new DVDButtonPane();
        buttonPane.relocate(10, 350);
        buttonPane.setPrefSize(800,40);

        getChildren().addAll(buttonPane, label1, label2, label3, label4, label5,label6, label7, saleNumText, amountPerSale, revenueText, sList, cList, pList);

        setPrefSize(800, 400);

    }

    public void update(ElectronicStore model, int selectedIndex) {

        stockList = FXCollections.observableArrayList();
        cartList = FXCollections.observableArrayList();
        ObservableList<String> popularList = FXCollections.observableArrayList();

        // display stock
        for (Product p : model.getStock()){
            if (p != null && p.getStockQuantity() > 0){
                stockList.add(p.toString());
            }
        }

        // add button
        buttonPane.getAddButton().setOnAction(event -> {
            String selectedItem = sList.getSelectionModel().getSelectedItem();
            if (selectedItem != null) {
                cartList.add(selectedItem);
                int index = sList.getSelectionModel().getSelectedIndex();
                Product product = model.getStock().get(index);

                int currentStockQuantity = product.getStockQuantity();
                product.setStockQuantity(currentStockQuantity-1);

                stockList.remove(selectedItem);
                sList.setItems(stockList);

                if (product.getStockQuantity() == 0) {
                    stockList.remove(selectedItem);
                    sList.setItems(stockList);
                }
            }
        });

        // remove button
        buttonPane.getRemoveButton().setOnAction(event -> {
            String selectedItem = cList.getSelectionModel().getSelectedItem();
            if (selectedItem != null) {
                cartList.remove(selectedItem);
            }
        });

        // sell button
        buttonPane.getCompleteButton().setOnAction(event -> {
            if (!cartList.isEmpty()) {
                // update num of sales
                numSales++;
                saleNumText.setText(Integer.toString(numSales));

                // update revenue
                for (String item : cartList) {
                    for (Product p: model.getStock()){
                        if (p.toString().equals(item)){
                            p.sellUnits(1);
                            revenue += p.getPrice();
                            revenueText.setText(Double.toString(revenue));
                            amountPerSale.setText(Double.toString(revenue/numSales));
                            popularList.add(item);
                        }
                    }
                }

                // reset cart
                cartList.clear();
                cList.setItems(cartList);
                buttonPane.getCompleteButton().setDisable(false);
            }
        });

        sList.setItems(stockList);
        cList.setItems(cartList);
        pList.setItems(popularList);

        // deactivate buttons
        boolean isStockItemSelected = (selectedIndex >= 0 && selectedIndex < stockList.size());
        boolean isCartItemSelected = (cList.getSelectionModel().getSelectedIndex() >= 0);
        boolean isCartEmpty = (cartList.size() == 0);
        buttonPane.getAddButton().setDisable(!isStockItemSelected);
        buttonPane.getRemoveButton().setDisable(!isCartItemSelected);
        buttonPane.getCompleteButton().setDisable(!(isCartEmpty));

        // display num of sales
        saleNumText.setText(Integer.toString(numSales));
        // display revenue
        revenueText.setText(Double.toString(revenue));
        // display $/Sale
        if (numSales == 0){
            amountPerSale.setText("N/A");
        }
        else{
            amountPerSale.setText(Double.toString(revenue/numSales));
        }
    }
}
