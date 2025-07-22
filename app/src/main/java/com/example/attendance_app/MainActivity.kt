package com.example.attendance_app

import android.os.Bundle
import android.text.method.ScrollingMovementMethod
import android.view.View
import android.widget.TextView
import android.widget.Toast
import androidx.appcompat.app.AppCompatActivity
import com.example.attendance_app.databinding.ActivityMainBinding
import kotlin.math.abs

class MainActivity : AppCompatActivity() {

    private lateinit var binding: ActivityMainBinding
    private var arrayData = mutableListOf<String>()
    private var linkedListHead: Node? = null
    private var arraySteps = 0
    private var linkedListSteps = 0
    private var arrayTotalTime = 0L
    private var linkedListTotalTime = 0L

    data class Node(val value: String, var next: Node?)

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        binding = ActivityMainBinding.inflate(layoutInflater)
        setContentView(binding.root)

        // Initialize scrolling for operation steps
        binding.stepDescription.movementMethod = ScrollingMovementMethod.getInstance()
        binding.stepDescription.isVerticalScrollBarEnabled = true

        setupClickListeners()
    }

    private fun setupClickListeners() {
        binding.checkInButton.setOnClickListener {
            val id = binding.studentIdInput.text.toString().trim()
            if (id.isEmpty()) {
                showToast("Please enter a Student ID")
                return@setOnClickListener
            }

            if (binding.radioArray.isChecked) {
                insertIntoArray(id)
                showArrayVisual()
            } else {
                insertIntoLinkedList(id)
                showLinkedListVisual()
            }
            updateSummary()
            binding.studentIdInput.text.clear()
        }

        binding.searchButton.setOnClickListener {
            val id = binding.studentIdInput.text.toString().trim()
            if (id.isEmpty()) {
                showToast("Please enter a Student ID")
                return@setOnClickListener
            }

            binding.stepDescription.append("\n=== SEARCH OPERATION ===\n")
            compareSearchPerformance(id)
            binding.studentIdInput.text.clear()
        }
    }

    private fun insertIntoArray(id: String) {
        val start = System.nanoTime()
        val steps = StringBuilder("\n=== INSERTING INTO ARRAY ===\n")

        // Remove duplicate if exists
        val existingIndex = arrayData.indexOf(id)
        if (existingIndex != -1) {
            arrayData.removeAt(existingIndex)
            steps.append("Step ${++arraySteps}: Removed duplicate at index $existingIndex\n")
        }

        // Make space and shift elements
        arrayData.add("")
        steps.append("Step ${++arraySteps}: Made space at end\n")
        for (i in arrayData.size - 1 downTo 1) {
            arrayData[i] = arrayData[i - 1]
            steps.append("Step ${++arraySteps}: Shifted from ${i-1} to $i\n")
        }

        // Insert new element
        arrayData[0] = id
        steps.append("Step ${++arraySteps}: Inserted at head\n")
        steps.append("Insert completed in ${(System.nanoTime() - start)/1000}μs\n")

        appendToStepLog(steps.toString())
        arrayTotalTime += System.nanoTime() - start
        showArrayVisual()
        updateSummary()
    }

    private fun insertIntoLinkedList(id: String) {
        val start = System.nanoTime()
        val steps = StringBuilder("\n=== INSERTING INTO LINKED LIST ===\n")

        // Remove duplicate if exists
        var prev: Node? = null
        var curr = linkedListHead
        while (curr != null) {
            if (curr.value == id) {
                steps.append("Step ${++linkedListSteps}: Found duplicate, removing\n")
                if (prev == null) {
                    linkedListHead = curr.next
                } else {
                    prev.next = curr.next
                }
                break
            }
            prev = curr
            curr = curr.next
        }

        // Insert new node at head
        linkedListHead = Node(id, linkedListHead)
        steps.append("Step ${++linkedListSteps}: Inserted at head\n")
        steps.append("Insert completed in ${(System.nanoTime() - start)/1000}μs\n")

        appendToStepLog(steps.toString())
        linkedListTotalTime += System.nanoTime() - start
        showLinkedListVisual()
        updateSummary()
    }

    private fun compareSearchPerformance(id: String) {
        binding.stepDescription.append("\n=== SEARCH PERFORMANCE ===\n")

        // Reset counters for clean measurement
        val arrayStepsBefore = arraySteps
        val listStepsBefore = linkedListSteps
        val arrayTimeBefore = arrayTotalTime
        val listTimeBefore = linkedListTotalTime

        // Execute searches
        val arrayFound = searchInArray(id)
        val listFound = searchInLinkedList(id)

        // Calculate metrics
        val arrayStepsUsed = arraySteps - arrayStepsBefore
        val listStepsUsed = linkedListSteps - listStepsBefore
        val arrayTimeUs = (arrayTotalTime - arrayTimeBefore) / 1000
        val listTimeUs = (linkedListTotalTime - listTimeBefore) / 1000
        val timeDiffUs = abs(arrayTimeUs - listTimeUs)

        // Build summary output
        val summary = """
        === PERFORMANCE SUMMARY ===
        Array (${arrayData.size} items):
        - Steps: $arrayStepsUsed
        - Time: ${arrayTimeUs}us
        - Found: ${if (arrayFound) "✅" else "❌"}
        - Access: Direct index (fast)

        Linked List (${getLinkedListSize()} items):
        - Steps: $listStepsUsed
        - Time: ${listTimeUs}us
        - Found: ${if (listFound) "✅" else "❌"}
        - Access: Node traversal (slow)


        Comparison:
        - Time difference: ${timeDiffUs}us
        - ${if (arrayTimeUs < listTimeUs) "Array was faster" else "Linked list was faster"}
        - Reason: ${getPerformanceReason(arrayTimeUs < listTimeUs)}
    """.trimIndent()

        binding.searchPerformance.text = summary
        scrollToBottom()
    }

    private fun getPerformanceReason(isArrayFaster: Boolean): String {
        return if (isArrayFaster) {
            "Arrays enable direct memory access via indexes while linked lists require node traversal"
        } else {
            "Linked list item was near head while array search required full scan"
        }
    }

    private fun searchInArray(id: String): Boolean {
        appendToStepLog("Searching array for '$id'...")
        val start = System.nanoTime()
        var found = false
        var position = -1

        for (i in arrayData.indices) {
            appendToStepLog("Step ${++arraySteps}: Checking index $i")
            if (arrayData[i] == id) {
                found = true
                position = i
                break
            }
        }

        val timeTaken = System.nanoTime() - start
        arrayTotalTime += timeTaken

        appendToStepLog(if (found) "✅ Found at index $position" else "❌ Not found")
        appendToStepLog("Search time: ${timeTaken/1000}μs")

        return found
    }

    private fun searchInLinkedList(id: String): Boolean {
        appendToStepLog("Searching linked list for '$id'...")
        val start = System.nanoTime()
        var found = false
        var position = 0
        var current = linkedListHead

        while (current != null) {
            appendToStepLog("Step ${++linkedListSteps}: Checking position $position")
            if (current.value == id) {
                found = true
                break
            }
            current = current.next
            position++
        }

        val timeTaken = System.nanoTime() - start
        linkedListTotalTime += timeTaken

        appendToStepLog(if (found) "✅ Found at position $position" else "❌ Not found")
        appendToStepLog("Search time: ${timeTaken/1000}μs")

        return found
    }

    private fun appendToStepLog(message: String) {
        runOnUiThread {
            binding.stepDescription.append("$message\n")
            scrollToBottom()
        }
    }

    private fun scrollToBottom() {
        binding.stepScrollView.post {
            binding.stepScrollView.fullScroll(View.FOCUS_DOWN)
        }
    }

    private fun showArrayVisual() {
        binding.visualContainer.removeAllViews()
        for ((index, id) in arrayData.withIndex()) {
            addVisualNode("[$id]\n$index")
        }
    }

    private fun showLinkedListVisual() {
        binding.visualContainer.removeAllViews()
        var node = linkedListHead
        while (node != null) {
            addVisualNode("[${node.value}] →")
            node = node.next
        }
        addVisualNode("NULL")
    }

    private fun addVisualNode(text: String) {
        val textView = TextView(this).apply {
            this.text = text
            setPadding(16, 16, 16, 16)
            setBackgroundResource(android.R.drawable.editbox_background)
        }
        binding.visualContainer.addView(textView)
    }

    private fun updateSummary() {
        val arrayTimeMs = arrayTotalTime / 1_000_000
        val linkedTimeMs = linkedListTotalTime / 1_000_000

        val arraySpace = arrayData.size * 40 // Approx bytes per string
        val linkedSpace = getLinkedListSize() * 48 // Approx bytes per node

        val summary = """
            🔢 Array Stats:
            - Items: ${arrayData.size}
            - Steps: $arraySteps
            - Time: ${arrayTimeMs}ms
            - Space: ~${arraySpace} bytes
            
            🧩 Linked List Stats:
            - Items: ${getLinkedListSize()}
            - Steps: $linkedListSteps
            - Time: ${linkedTimeMs}ms
            - Space: ~${linkedSpace} bytes
        """.trimIndent()

        binding.statSummary.text = summary
    }

    private fun getLinkedListSize(): Int {
        var count = 0
        var node = linkedListHead
        while (node != null) {
            count++
            node = node.next
        }
        return count
    }

    private fun showToast(message: String) {
        Toast.makeText(this, message, Toast.LENGTH_SHORT).show()
    }
}